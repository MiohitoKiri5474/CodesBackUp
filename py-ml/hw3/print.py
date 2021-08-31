import pickle

file = open ( "./mio.pickle", "rb" )
data = pickle.load ( file )
file.close()

print ( data )
