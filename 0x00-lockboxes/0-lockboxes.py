#!/usr/bin/python3
""" method that determines if all the boxes can be opened. """


def canUnlockAll(boxes):
    """Open all boxes"""
    len_boxes = len(boxes)
    if not len_boxes:
        return False
    unlock = [0]

    for key in unlock:
        for box in boxes[key]:
            if box not in unlock and box < len_boxes:
                unlock.append(box)

    if len(unlock) == len_boxes:
        return True

    return False
