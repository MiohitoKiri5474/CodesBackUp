import pickle
from os import path
import numpy as np

def get_ArkanoidData(filename):
    file = open(filename,'rb')
    log = pickle.load(file)
    Frames = []
    Balls = []
    Commands = []
    PlatformPos = []
    for sceneInfo in log:
        Frames.append(sceneInfo.frame)
        Balls.append([sceneInfo.ball[0], sceneInfo.ball[1]])
        Commands.append(str(sceneInfo.command))
        PlatformPos.append(sceneInfo.platform)

    commands_ary = np.array([Commands])
    commands_ary = commands_ary.reshape((len(Commands), 1))
    frame_ary = np.array(Frames)
    frame_ary = frame_ary.reshape((len(Frames), 1))
    data = np.hstack((frame_ary, Balls, PlatformPos, commands_ary))
    return data

if __name__ == '__main__':
    filename = path.join(path.dirname(__file__), 'arkanoid_EASY_1.pickle')
    data = get_ArkanoidData(filename)
    print(data)
    X = data[:, :-1]
    Y = data[:, -1]
    print(X)
    # print(Y)
