//
//  main.swift
//  1260
//
//  Created by 유현진 on 2021/09/08.
//

import Foundation

var input = readLine()!.components(separatedBy: " ").map() {Int($0)!}

let N = input[0] //정점의 개수
let M = input[1] //간선의 개수
let S = input[2] //탐색을 시작할 번호
var graph = [Int: [Int]]()

var v = [Int]()

//init graph
for _ in 0..<M{
    input = readLine()!.components(separatedBy: " ").map() {Int($0)!}
    let s = input[0]
    let e = input[1]
    if graph[s] == nil{  // 딕셔너리로 그래프 만들기
        graph[s] = [e]
    }else{
        graph[s]?.append(e) // 왜 왜 왜 왜 왜 옵셔널이냐? ->
    }
    if graph[e] == nil{
        graph[e] = [s]
    }else{
        graph[e]?.append(s)
    }
}
func dfs(_ graph: [Int: [Int]], _ s: Int) -> [Int]{
    var visited = [Int]()
    var stack = [s]
    while stack.count != 0{
        if let node = stack.popLast(){
            if !visited.contains(node){
                visited.append(node)
                if let moreDept = graph[node]{
                    stack += moreDept
                }
            }
        }
    }
    return visited
}

func bfs(_ graph: [Int: [Int]], _ s: Int) -> [Int]{
    var visited = [Int]()
    var queue = [s]
    
    while queue.count != 0{
        let node = queue.removeFirst()
        if !visited.contains(node){
            visited.append(node)
            if let near = graph[node]{
                queue += near
            }
        }
    }
    return visited
}



for key in graph.keys{
    graph[key]?.sort(by: >)
}
var dfsResult = ""
for i in dfs(graph, S){
    dfsResult += String(i) + " "
}


for key in graph.keys{
    graph[key]?.sort(by: <)
}
var bfsResult = ""
for i in bfs(graph, S){
    bfsResult += String(i) + " "
}

print(dfsResult)
print(bfsResult)
