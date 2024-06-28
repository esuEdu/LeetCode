//
//  test.swift
//  FindCommonCharacters
//
//  Created by Eduardo on 05/06/24.
//

import Foundation

class Test {
    func commonChars(_ words: [String]) -> [String] {
        var dic: [Character: Int] = [:]

        var str: [String] = []

        for char in words[0] {
            dic[char] = (dic[char] ?? 0) + 1
        }

        for word in words.dropFirst() {
            var currentCount: [Character: Int] = [:]
            for char in word {
                currentCount[char] = (currentCount[char] ?? 0) + 1
            }

            for char in dic.keys {
                if let count = currentCount[char] {
                    dic[char] = min(dic[char]!, count)
                } else {
                    dic[char] = 0
                }
            }
        }
        
        for (key, value) in dic {
            for _ in 0..<value {
                str.append(String(key))
            }
        }
        
        return str
    }
}
