g++ gen.cpp -o gen
g++ bru.cpp -o bru
g++ prp.cpp -o prp
for i in {1..10000}
do
echo $i
./gen <<<$i > in.in
./bru < in.in > out1.out
./prp < in.in > out2.out
diff -w out1.out out2.out || break
done
