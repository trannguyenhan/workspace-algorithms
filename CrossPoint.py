def pos(point):
    if point[0]==0 and point[1]==0 : 
        return 0 # nam tren goc toa do
    elif point[0]>0 and point[1]>0 :
        return 1 # nam tren goc phan tu thu nhat
    elif point[0]>0 and point[1]<0: 
        return 4 # nam tren goc phan tu thu tu
    elif point[0]<0 and point[1]<0:  
        return 3 # nam tren goc phan tu thu ba
    elif point[0]<0 and point[1]>0: 
        return 2 # nam tren goc phan tu thu hai
    elif point[0]==0 and point[1]>0:
        return -1 # nam tren chieu duong truc ox
    elif point[0]==0 and point[1]<0:
        return -2 # nam tren chieu am truc ox
    elif point[0]>0 and point[1]==0: 
        return -3 # nam tren chieu duong truc oy
    elif point[0]<0 and point[1]==0:
        return -4 # nam tren chieu am truc oy

def cross(points):
    point1 = points[1]
    point2 = points[2]
    point3 = points[3]

    crossArr = []
    #xet 2 diem point1, point2 truoc: 
    
