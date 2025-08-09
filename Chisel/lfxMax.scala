package stack

import chisel3.stage.ChiselStage
import chisel3.experimental.ChiselEnum
import java.nio.file.Paths

import chisel3._
import chisel3.util._

// Your code starts here
object Opcode extends ChiselEnum {
  val push  = Value(0x27.U)
  val peek  = Value(0x40.U)
  val pop   = Value(0x43.U)
}

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

  // Convenience values
  val emptyEntry = 0.U(dataWidth.W)
  val immWidth = 25
  val stackPtrBits = (log2Ceil(len+1)).W
  val botPtr = 0.U(stackPtrBits)
  val topPtr = len.U(stackPtrBits)
  // To zero extend the immediate into the stack, dataWidth must be wider
  val inData = Wire(UInt(dataWidth.W))

  // Intermediate signals for MUXes
  val opcode = io.in(6,0)
  val imm = io.in(31,7)
  val isPush = opcode === Opcode.push.asUInt
  val isPeek = opcode === Opcode.peek.asUInt
  val isPop = opcode === Opcode.pop.asUInt
  val isRead = isPeek | isPop
  val noneSet = ~(imm.orR)

  // Registers for stack
  val stack = RegInit(VecInit(Seq.fill(len)(emptyEntry)))
  val stackPtr = RegInit(botPtr)
  val stackPtrNext = stackPtr + 1.U
  val stackPtrPrev = stackPtr - 1.U

  // Output flags all change along with stackPtr, on a rising edge
  val isEmpty = stackPtr === botPtr
  val isFull = stackPtr === topPtr
  val underflow = isRead & noneSet & isEmpty
  val overflow = isPush & isFull
  val popped = isPop & noneSet & ~isEmpty
  val peeked = isPeek & noneSet & ~isEmpty

  // Stack output data (output valid data or 0 by default)
  val ptr = Mux(~isEmpty, stackPtrPrev, botPtr)
  val out = Mux(isRead & noneSet & ~isEmpty, stack(ptr), emptyEntry)

  // Depending on the module parameterization
  if (dataWidth > immWidth) {
    inData := Cat(0.U((dataWidth-immWidth).W), imm)
  } else {
    inData := imm(dataWidth-1,0)
  }

  // Increment/decrement pointer
  when (isPush & ~isFull) {
    stack(stackPtr) := inData
    stackPtr := stackPtrNext
  } .elsewhen (popped) {
    stackPtr := stackPtrPrev
  }

  // Connect local signals to IO
  io.out := RegNext(out)
  io.underflow := RegNext(underflow)
  io.overflow := RegNext(overflow)
  io.isEmpty := isEmpty
  io.isFull := isFull
  io.popped := RegNext(popped)
  io.peeked := RegNext(peeked)
}
// Your code ends here

object SVGen extends App {
  val out = Paths.get(
    "out",
    this.getClass
      .getName
      .stripSuffix("$")
  ).toString
  new ChiselStage().emitSystemVerilog(
    new StackModule(args(0).toInt, args(1).toInt),
    Array("--target-dir", out),
  )
}
