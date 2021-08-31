import gym
import numpy as np
import math

env = gym.make ( 'CartPole-v0' )

def value ( state, table, actSpace, eps ):
    if np.random.random_sample() < eps:
        return actSpace.sample()
    return np.argmax ( table[state] )

def getStatus ( obs, buckets, bounds ):
    state = [0] * len ( obs )
    for i, s in enumerate ( obs ):
        l, u = bounds[i][0], bounds[i][1]
        
        if s <= l:
            state[i] = 0
        elif s >= u:
            state[i] = buckets[i] - 1
        else:
            state[i] = int ( ( ( s - l ) / ( u - l ) ) * buckets[i] )

    return tuple ( state )

buckets = ( 1, 1, 6, 3 )

actions = env.action_space.n

bounds = list ( zip ( env.observation_space.low, env.observation_space.high ) )
bounds[1] = [-0.5, 0.5]
bounds[3] = [-math.radians ( 50 ), math.radians ( 50 )]

table = np.zeros ( buckets + ( actions, ) )

getEpsilon = lambda i: max ( 0.01, min ( 1, 1.0 - math.log10 ( ( i + 1 ) / 25 ) ) )
getLR = lambda i: max ( 0.01, min ( 0.5, 1.0 - math.log10 ( ( i + 1 ) / 25 ) ) )
gamma = 0.99

result = []

for tms in range ( 500 ):
    eps = getEpsilon ( tms )
    lr = getLR ( tms )
    obs = env.reset()
    scores = 0
    state = getStatus ( obs, buckets, bounds )

    for i in range ( 500 ):
        env.render()

        act = value ( state, table, env.action_space, eps )
        obs, score, done, info = env.step ( act )

        scores += score
        nxt = getStatus ( obs, buckets, bounds )

        qNxt = np.amax ( table[nxt] )
        table[state + ( act, )] += lr * ( score + gamma * qNxt - table[state + ( act, )] )

        state = nxt

        if done:
            result.append ( scores )
            break

for i in result:
    print ( i )
env.close()
