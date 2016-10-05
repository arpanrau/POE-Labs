import pickle
data = pickle.load( open('save.p','rb'))

textfile = open("Output.txt", "w")
                
for i in data:
    textfile.write(i)

textfile.close()
