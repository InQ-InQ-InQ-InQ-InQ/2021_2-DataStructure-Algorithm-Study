//
//  main.swift
//  11729
//
//  Created by 유현진 on 2021/10/04.
//

import Foundation

func solution(){
    let N = Int(readLine()!)!
    
    var count = 0
    var result = [String]()
    func hanoi(_ n: Int, _ src: Int, _ dst: Int, _ tmp: Int){
        if n>0{
            hanoi(n-1, src, tmp, dst)
            count += 1
            result.append("\(src) \(dst)")
            hanoi(n-1, tmp, dst, src) //
        }
    }
    hanoi(N, 1, 3, 2)
    
    print(count)
    for i in result{
        print(i)
    }
}
solution()
// 1회에 N-1만큼 원판을 옮겨야 함



