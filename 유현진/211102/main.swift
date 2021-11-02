import Foundation

func solution(){
    let input = readLine()!.split(separator: " ").compactMap{ Int(String($0))}
    let _ = input[0]
    let M = input[1]
    let t = readLine()!.split(separator: " ").compactMap{ Int(String($0))}
    var result = 0
    var sum = 0
    let top = t.max()!
    
    binarySearch(0, top)
    print(result)
    func binarySearch(_ low: Int, _ top: Int){
        sum = 0
        let height = (low + top) / 2
        if low > top{
            return
        }
        for i in t{
            if i > height{
                sum += i - height
            }
        }
        
        if sum >= M{
            result = height
            binarySearch(height+1, top)
        }else{
            binarySearch(low ,height-1)
        }
    }
}
solution()
