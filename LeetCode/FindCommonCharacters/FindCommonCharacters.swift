//
//  FindCommonCharacters.swift
//  LeetCode
//
//  Created by Eduardo on 05/06/24.
//

import Foundation

class FindCommonCharacters {
    func commonChars(_ words: [String]) -> [String] {
        
        var str: [Character] = []
        
        for (index, word) in words.enumerated() {
            var charToKeep: [Character] = []
            for char in word {
                
                if index == 0 {
                    str.append(char)
                }else if str.contains(char) {
                    charToKeep.append(char)
                }
            }
            if index != 0 {
                str = str.filter { charToKeep.contains($0)}
            }
        }
        return str.map { $0.description }
    }
}
