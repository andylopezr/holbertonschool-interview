#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1
and each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """ Method to determine if all boxes can be opened """
    if not boxes or len(boxes) == 0:
        return False
    length = len(boxes)
    counter = 1
    keys = [0]
    for key in keys:
        for n in boxes[key]:
            if n not in keys:
                if n != key and n < length:
                    counter += 1
                    keys.append(n)
    if counter == length:
        return True
    return False
