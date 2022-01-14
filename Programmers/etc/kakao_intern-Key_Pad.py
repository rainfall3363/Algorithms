def solution(numbers, hand):
    answer = ""
    numpad_coordinate = { 1:[0, 0], 2:[0, 1], 3: [0, 2], 4:[1, 0], 5:[1, 1], 6:[1, 2], 7:[2, 0], 8:[2, 1], 9:[2, 2], 0:[3, 1] } 
    left_thumb_coordinate = [3, 0]
    right_thumb_coordinate = [3, 2]
    
    for i in numbers:
        if i in [1, 4, 7]:
            answer += 'L'
            left_thumb = left_thumb_coordinate = numpad_coordinate[i]
        elif i in [3, 6, 9]:
            answer += 'R'
            right_thumb_coordinate = numpad_coordinate[i]
        else:        
            left_thumb_distance = abs(left_thumb_coordinate[0] - numpad_coordinate[i][0]) + abs(left_thumb_coordinate[1] - numpad_coordinate[i][1])
            right_thumb_distance = abs(right_thumb_coordinate[0] - numpad_coordinate[i][0]) + abs(right_thumb_coordinate[1] - numpad_coordinate[i][1])

            if left_thumb_distance < right_thumb_distance:
                answer += 'L'
                left_thumb_coordinate = numpad_coordinate[i]
            elif left_thumb_distance > right_thumb_distance:
                answer += 'R'
                right_thumb_coordinate = numpad_coordinate[i]
            else:
                if hand == "left":
                    answer += 'L'
                    left_thumb_coordinate = numpad_coordinate[i]
                else:
                    answer += 'R'
                    right_thumb_coordinate = numpad_coordinate[i]
                
    return answer
