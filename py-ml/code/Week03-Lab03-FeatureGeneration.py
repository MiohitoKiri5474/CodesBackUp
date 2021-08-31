import pickle
from os import path
import numpy as np


def transformCommand(command):
    if 'RIGHT' in str(command):
       return 2
    elif 'LEFT' in str(command):
        return 1
    else:
        return 0
    pass


def get_ArkanoidData(filename):
    Frames = []
    Balls = []
    Commands = []
    PlatformPos = []
    log = pickle.load((open(filename, 'rb')))
    for sceneInfo in log:
        Frames.append(sceneInfo.frame)
        Balls.append([sceneInfo.ball[0], sceneInfo.ball[1]])
        # Commands.append(sceneInfo.command)
        PlatformPos.append(sceneInfo.platform)
        Commands.append(transformCommand(sceneInfo.command))

    commands_ary = np.array([Commands])
    commands_ary = commands_ary.reshape((len(Commands), 1))
    frame_ary = np.array(Frames)
    frame_ary = frame_ary.reshape((len(Frames), 1))
    data = np.hstack((frame_ary, Balls, PlatformPos, commands_ary))
    return data


if __name__ == '__main__':
    filename = path.join(path.dirname(__file__), 'arkanoid_EASY_1.pickle')
    data = get_ArkanoidData(filename)
    Balls = data[:, 1:3]
    print(Balls)
    Balls_next = np.array(Balls[1:])
    vectors = Balls_next - Balls[:-1]
    print('vectors = ', vectors)

    data = np.hstack((data[1:, :], vectors))
    mask = [0, 1, 2, 3, 4, 6, 7]
    X = data[:, mask]
    Y = data[:, -3]
    print(X)
    print(Y)
