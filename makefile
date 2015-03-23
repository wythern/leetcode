CC := g++
CFLAGS := -g -Wall -I ./
object := ${FILE}

target: ${FILE}
       ${CC} -o3 ${CFLAGS} ${object}.cpp -o ${object}


