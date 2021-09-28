import Foundation
func solution(){
    let input = readLine()!.components(separatedBy: " ").map() {Int($0)!}
    var map = [[Int]]()
    var queue = [[0,0]]
    

    for _ in 0..<input[0]{
        map.append(readLine()!.map({Int(String($0))!}))
    }

    
    while queue.count != 0{
        let v = queue.removeFirst()
        let x = v[0]
        let y = v[1]
        
        if x == input[0]-1, y == input[1]-1{
            print(map[x][y])
            return
        }
        
        if x+1 <= input[0]-1{
            if map[x+1][y] == 1{ //하
                map[x+1][y] = map[x][y] + 1
                queue.append([x+1, y])
            }
        }
        if y-1 >= 0{
            if map[x][y-1] == 1{ //좌
                map[x][y-1] = map[x][y] + 1
                queue.append([x, y-1])
            }
        }
        if x-1 >= 0{
            if map[x-1][y] == 1{ //상
                map[x-1][y] = map[x][y] + 1
                queue.append([x-1, y])
            }
        }
        
        if y+1 <= input[1]-1{
            if map[x][y+1] == 1{ //우
                map[x][y+1] = map[x][y] + 1
                queue.append([x, y+1])
            }
        }
        
        
        
    }
}

solution()
