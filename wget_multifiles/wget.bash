#http://gow.nike.com.cn/wk/link/imgs/wallpaper/wallpaper_047.jpg
count=10
while [ $count -lt 48 ]
do
    echo $count
    wget "http://gow.nike.com.cn/wk/link/imgs/wallpaper/wallpaper_0$count.jpg"
    count=`expr $count + 1`
done
