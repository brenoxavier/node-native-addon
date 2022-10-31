import { Graph } from './graph'

const graph = new Graph(200)

graph.setNode(0, 0, 25)
graph.setNode(1, 44, 762)
graph.setNode(2, 24, 76)
graph.setNode(3, 9, 565)
graph.setNode(4, 8, 98)
graph.setNode(5, 7, 234)
graph.setNode(6, 5, 84)
graph.setNode(7, 2, 14)

console.log(graph.getNode(0, 0))
console.log(graph.getNode(1, 44))
console.log(graph.getNode(2, 24))
console.log(graph.getNode(3, 9))
console.log(graph.getNode(4, 8))
console.log(graph.getNode(5, 7))
console.log(graph.getNode(6, 5))
console.log(graph.getNode(7, 2))
