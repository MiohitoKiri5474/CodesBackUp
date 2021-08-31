import pickle
import numpy as np
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split, cross_val_score
from sklearn.metrics import  classification_report, confusion_matrix
from sklearn.model_selection import GridSearchCV
from sklearn.model_selection import StratifiedShuffleSplit

#試取資料
file = open("./a1.pickle", "rb")
data = pickle.load(file)
file.close()
# print ( data )


game_info = data['ml']['scene_info']
game_command = data['ml']['command']


for i in range(2, 27):
    path = "./a" + str(i) + ".pickle"
    file = open(path, "rb")
    data = pickle.load(file)
    game_info = game_info + data['ml']['scene_info']
    game_command = game_command + data['ml']['command']
    file.close()
    

g = game_info[1]

feature = np.array ( [g['snake_head'][0], g['snake_head'][1]] )

game_command[1] = 0


cnt = 0
print ( len ( game_info ) )
for i in range(2, len(game_info) - 1):
    if i % 10000 == 0:
        cnt = cnt + 1;
        print ( "now adding", cnt )
    f = game_info[i - 1]
    g = game_info[i]
    feature = np.vstack((feature, [g['snake_head'][0], g['snake_head'][1]]))
    if game_command[i] == "NONE":
        game_command[i] = 0
    elif game_command[i] == "UP":
        game_command[i] = 1
    elif game_command[i] == "DOWN":
        game_command[i] = 2
    elif game_command[i] == "LEFT":
        game_command[i] = 3
    else:
        game_command[i] = 4
    
answer = np.array(game_command[1:-1])



#資料劃分
x_train, x_test, y_train, y_test = train_test_split(feature, answer, test_size=0.3, random_state=9)
#參數區間
param_grid = {'n_neighbors':[1, 2, 3]}
#交叉驗證 
cv = StratifiedShuffleSplit(n_splits=3, test_size=0.3, random_state=12)
grid = GridSearchCV(KNeighborsClassifier(), param_grid, cv=cv, verbose=10, n_jobs=-1) #n_jobs為平行運算的數量
grid.fit(x_train, y_train)
grid_predictions = grid.predict(x_test)

#儲存
file = open('../ml/mio.pickle', 'wb')
pickle.dump(grid, file)
file.close()



#最佳參數
print ( "best:" )
print(grid.best_params_)
#預測結果
#print(grid_predictions)
#混淆矩陣
print(confusion_matrix(y_test, grid_predictions))
#分類結果
print(classification_report(y_test, grid_predictions))
