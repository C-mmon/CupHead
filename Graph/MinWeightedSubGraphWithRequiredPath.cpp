//3 djkistra required
// one from node a to all the other node in array 
// node b to all the other node in array
// from node dest to all the other node via reversed graph
// ans is min of da[i] + db[i] + dd[i]
// ideally we have to move from "src1" and "src2" to "dest",
// We are meeting in middle somewhere, so we have to traverse back from "dest" to some node "i".
// In order to move backwords, we need the reversed adjacency list.