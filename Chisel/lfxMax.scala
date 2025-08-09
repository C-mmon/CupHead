package stack

import chisel3.stage.ChiselStage
import chisel3._
import chisel3.util._
import java.nio.file.Paths

class StackModule(val dataWidth: Int, val len: Int) extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(32.W))
    val out = Output(UInt(dataWidth.W))
    val underflow = Output(Bool())
    val overflow = Output(Bool())
    val isEmpty = Output(Bool())
    val isFull = Output(Bool())
    val popped = Output(Bool())
    val peeked = Output(Bool())
  })

  // Stack and pointer initialization
  val stack = RegInit(VecInit(Seq.fill(len)(0.U(dataWidth.W))))
  val stackPtr = RegInit(0.U(log2Ceil(len + 1).W))

  // Combinational status flags
  val isEmpty = stackPtr === 0.U
  val isFull = stackPtr === len.U

  // Extract instruction fields
  val opcode = io.in(6, 0)
  val data = io.in(31, 7)
  
  // Opcodes
  val pushOp = "b0100111".U
  val popOp = "b1000011".U
  val peekOp = "b1000000".U

  // Operation flags (combinational)
  val underflow = (opcode === peekOp || opcode === popOp) && isEmpty
  val overflow = opcode === pushOp && isFull
  val popped = opcode === popOp && !isEmpty
  val peeked = opcode === peekOp && !isEmpty

  // Output data (combinational)
  val outData = Mux(!isEmpty && (opcode === peekOp || opcode === popOp), stack(stackPtr - 1.U), 0.U(dataWidth.W))

  // Handle data input with zero-extension if needed
  val inData = if (dataWidth > 25) Cat(0.U((dataWidth - 25).W), data) else data(dataWidth - 1, 0)

  // Stack operations
  when(reset.asBool) {
    stackPtr := 0.U
  }.otherwise {
    when(opcode === pushOp && !isFull) {
      stack(stackPtr) := inData
      stackPtr := stackPtr + 1.U
    }.elsewhen(opcode === popOp && !isEmpty) {
      stackPtr := stackPtr - 1.U
    }
  }

  // Registered outputs
  io.out := RegNext(outData)
  io.underflow := RegNext(underflow)
  io.overflow := RegNext(overflow)
  io.popped := RegNext(popped)
  io.peeked := RegNext(peeked)
  io.isEmpty := isEmpty
  io.isFull := isFull
}

object SVGen extends App {
  val out = Paths.get("out", this.getClass.getName.stripSuffix("$")).toString
  new ChiselStage().emitSystemVerilog(
    new StackModule(args(0).toInt, args(1).toInt),
    Array("--target-dir", out)
  )
}
