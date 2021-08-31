"""
The template of the main script of the machine learning process
"""
import random
import os.path
import pickle

class MLPlay:
    def __init__(self):
        """
        Constructor
        """
        filename = 'mio.pickle'
        filepath = os.path.join(os.path.dirname(__file__), filename)
        self.model = pickle.load(open(filepath, 'rb'))
        self.ball_served = False
        self.pre_x = 0
        self.pre_y = 0

    def update(self, scene_info):
        """
        Generate the command according to the received `scene_info`.
        """
        # Make the caller to invoke `reset()` for the next round.
        if (scene_info["status"] == "GAME_OVER" or
            scene_info["status"] == "GAME_PASS"):
            return "RESET"

        if not self.ball_served:
            self.ball_served = True
            command = "SERVE_TO_LEFT"
        else:
            command = self.model.predict([[scene_info["ball"][0], scene_info["ball"][1], scene_info["platform"][0], scene_info['ball'][0] - self.pre_x, scene_info['ball'][1] - self.pre_y]])

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
