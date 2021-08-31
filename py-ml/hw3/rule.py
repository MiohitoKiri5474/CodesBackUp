"""
The template of the script for playing the game in the ml mode
"""

class MLPlay:
    def __init__(self):
        """
        Constructor
        """
        self.flag = False

    def update(self, scene_info):
        """
        Generate the command according to the received scene information
        """
        if scene_info["status"] == "GAME_OVER":
            return "RESET"

        if scene_info["frame"] > 1000:
            return "NONE"

        x, y = scene_info["snake_head"][0], scene_info["snake_head"][1] / 10
        if x == 40 and y == 4:
            return "RIGHT"
        if x == 0 and y == 0:
            return "RIGHT"
        if ( x == 10 and y == 29 ) or ( x == 10 and y == 0 ):
            return "NONE"
        if x == 0 and y == 29:
            return "UP"
        if ( x != 10 and x != 290 ) or x == 0:
            return "NONE"
        else:
            if x == scene_info["snake_body"][0][0]:
                if y % 2 == 0:
                    return "RIGHT"
                elif y % 2 == 1:
                    return "LEFT"
            else:
                return "DOWN"

        return "NONE"
        

    def reset(self):
        """
        Reset the status if needed
        """
        pass
