const addon = require('../build/Release/Addon')

export interface Graph {
    setNode(x: number, z: number, block: number): void,
    getNode(x: number, z: number): number
}

export const Graph: {
    new(size: number): Graph
} = addon.Graph
