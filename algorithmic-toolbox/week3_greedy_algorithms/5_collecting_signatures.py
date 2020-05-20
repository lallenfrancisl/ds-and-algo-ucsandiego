# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')


def comp(tup):
    return tup.end


def optimal_points(segments):
    points = []

    # sort the segments in the increasing order of its end
    segments = sorted(segments, key=comp)

    # add the end of the first point to the solution points
    gues_point = segments[0].end
    points.append(segments[0].end)

    leng = len(segments)
    s = 0
    while s < leng:
        # add the current segment's end point to the result points if the current point is not in the current segment
        if not ((gues_point >= segments[s].start) and (gues_point <= segments[s].end)):
            # change the current point to the end of the current segment
            gues_point = segments[s].end
            points.append(segments[s].end)

        s += 1

    return points


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    print(*points)
