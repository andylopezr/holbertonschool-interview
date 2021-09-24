#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """
    Return: True if data is a valid UTF-8 encoding, else return False
    """
    byteCounter = 0
    firstVersion = 1 << 7
    secondVersion = 1 << 6

    for i in data:
        maskNbyte = 1 << 7
        if byteCounter == 0:
            while maskNbyte & i:
                byteCounter += 1
                maskNbyte = maskNbyte >> 1

            if byteCounter == 0:
                continue
            if byteCounter == 1 or byteCounter > 4:
                return False
        else:
            if not (i & firstVersion and not (i & secondVersion)):
                return False
        byteCounter -= 1
    if byteCounter == 0:
        return True
    return False
