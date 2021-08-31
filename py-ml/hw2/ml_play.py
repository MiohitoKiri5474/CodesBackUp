"""
The template of the main script of the machine learning process
"""
import random
import os.path
import pickle

class MLPlay:
    def __init__(self, side):
        """
        Constructor
        """
        filename = 'mio_1P.pickle'
        filepath = os.path.join(os.path.dirname(__file__), filename)
        self.model_1P = pickle.load(open(filepath, 'rb'))
        filename = 'mio_2P.pickle'
        filepath = os.path.join(os.path.dirname(__file__), filename)
        self.model_2P = pickle.load(open(filepath, 'rb'))
        self.ball_served = False
        self.pre_x = 0
        self.pre_y = 0
        self.side = side

    def update(self, scene_info):
        """
        Generate the command according to the received `scene_info`.
        """
        # Make the caller to invoke `reset()` for the next round.
        if (scene_info["status"] == "GAME_2P_WIN" or
            scene_info["status"] == "GAME_1P_WIN" or
            scene_info["status"] == "GAME_DRAW"):
            return "RESET"

        if not self.ball_served:
            self.ball_served = True
            command = "SERVE_TO_LEFT"
        else:
            if self.side == "1P":
                command = self.model_1P.predict([[scene_info["ball"][0], scene_info["ball"][1], scene_info["platform_1P"][0], scene_info['ball'][0] - self.pre_x, scene_info['ball'][1] - self.pre_y]])
            else:
                command = self.model_2P.predict([[scene_info["ball"][0], scene_info["ball"][1], scene_info["platform_2P"][0], scene_info['ball'][0] - self.pre_x, scene_info['ball'][1] - self.pre_y]])

            self.pre_x = scene_info['ball'][0]
            self.pre_y = scene_info['ball'][1]


        if command == 0: return "NONE"
        elif command == 1: return "MOVE_LEFT"
        else: return "MOVE_RIGHT"

    def reset(self):
        """
        Reset the status
        """
        self.ball_served = False
