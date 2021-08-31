"""
The template of the main script of the machine learning process
"""

import random
import pickle


class MLPlay:
    
    def __init__(self):
        """
        Constructor
        """
        self.previous_ball = ( 0, 0 )
        self.ball_served = False
        # filepath = "./test.pickle"
        # with open ( filepath, 'rb' ) as f:
            # data = pickle.load ( f )

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
            num = random.random()
            if num < 0.5:
                command = "SERVE_TO_LEFT"
            else:
                command = "SERVE_TO_RIGHT"
        else:
            x = scene_info["ball"][0]
            y = scene_info["ball"][1]

            px = self.previous_ball[0]
            py = self.previous_ball[1]


            if px - x == 0:
                self.previous_ball = scene_info["ball"]
                return "NONE"

            if py >= y:
                self.previous_ball = scene_info["ball"]
                return "NONE"


            m = ( py - y ) / ( px - x )           

            if m == 0:
                return "NONE"

            pos = ( 400 - y ) / m + x

            while pos < 0 or pos > 200:
                if pos < 0:
                    pos = abs ( pos )
                else:
                    pos = 200 - abs ( pos - 200 )

            plat = scene_info["platform"][0]
            command = "NONE"

            if plat > pos:
                command = "MOVE_LEFT"
            elif plat + 40 < pos:
                command = "MOVE_RIGHT"


        self.previous_ball = scene_info["ball"]
        return command

    def reset(self):
        """
        Reset the status
        """
        self.ball_served = False
