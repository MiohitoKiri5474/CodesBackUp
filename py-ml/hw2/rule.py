"""
The template of the script for the machine learning process in game pingpong
"""

import random
import pickle

class MLPlay:
    def __init__(self, side):
        """
        Constructor

        @param side A string "1P" or "2P" indicates that the `MLPlay` is used by
               which side.
        """
        self.ball_served = False
        self.side = side
        self.data = []

    def update(self, scene_info):
        """
        Generate the command according to the received scene information
        """
        if scene_info["status"] != "GAME_ALIVE":
            return "RESET"

        command = "NONE"

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

            m = scene_info["ball_speed"][1] / scene_info["ball_speed"][0]

            if m == 0:
                command = "NONE"
            elif self.side == "1P":
                pos = ( 420 - y ) / m + x

                while pos < 0 or pos > 200:
                    if pos < 0:
                        pos = abs ( pos )
                    else:
                        pos = 200 - abs ( pos - 200 )


                plat = scene_info["platform_1P"][0]
                command = "NONE"

                if plat + 5 > pos:
                    command = "MOVE_LEFT"
                elif plat + 35 < pos:
                    command = "MOVE_RIGHT"
            else:
                pos = ( 80 - y ) / m + x
                
                while pos < 0 or pos > 200:
                    if pos < 0:
                        pos = abs ( pos )
                    else:
                        pos = 200 - abs ( pos - 200 )

                plat = scene_info["platform_2P"][0]
                command = "NONE"

                if plat + 5 > pos:
                    command = "MOVE_LEFT"
                elif plat + 35 < pos:
                    command = "MOVE_RIGHT"

        return command

    def reset(self):
        """
        Reset the status
        """
        self.ball_served = False
