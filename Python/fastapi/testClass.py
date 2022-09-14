class Test:
    def __init__ ( self, _int, _str ):
        self.num = _int
        self.name = _str

    def Print ( self ):
        print ( self.num, self.name )


testing = Test ( 10, "abc" )

testing.Print()
