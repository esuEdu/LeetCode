//
//  main.swift
//  LeetCode
//
//  Created by Eduardo on 05/06/24.
//

import Foundation

let solution = FindCommonCharacters()
let test = Test()

//Input: words = ["bella","label","roller"]
//Output: ["e","l","l"]

//Input: words = ["cool","lock","cook"]
//Output: ["c","o"]

let wordsInput = ["bella","label","roller"]

let startTime = CFAbsoluteTimeGetCurrent()
let result = solution.commonChars(wordsInput)
let timeElapsed = CFAbsoluteTimeGetCurrent() - startTime

let startTime2 = CFAbsoluteTimeGetCurrent()
let result2 = test.commonChars(wordsInput)
let timeElapsed2 = CFAbsoluteTimeGetCurrent() - startTime

print(result)
print(result2)
print("Time elapsed: \(timeElapsed) seconds")
print("Time elapsed2: \(timeElapsed) seconds")
