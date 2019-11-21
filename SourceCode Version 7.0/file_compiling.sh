
echo "LAC:"
echo "compiling encoder"
cd LAC && g++ encoder.cpp -o main1 
echo "compiling decoder" 
g++ decoder.cpp -o main 
cd ..


echo "IAC:"
echo "compiling encoder"
cd IAC && g++ encoder.cpp -o main1 
echo "compiling decoder" 
g++ decoder.cpp -o main 
cd ..


echo "UAC:"
echo "compiling encoder"
cd UAC && g++ encoder.cpp -o main1 
echo "compiling decoder" 
g++ decoder.cpp -o main 
cd ..

echo "LPC:"
echo "compiling encoder"
cd LPC && g++ encoder.cpp -o main1 
echo "compiling decoder" 
g++ decoder.cpp -o main 
cd ..


echo "IPC:"
echo "compiling encoder"
cd IPC && g++ encoder.cpp -o main1 
echo "compiling decoder" 
g++ decoder.cpp -o main 
cd ..


echo "UPC:"
echo "compiling encoder"
cd UPC && g++ encoder.cpp -o main1 
echo "compiling decoder" 
g++ decoder.cpp -o main 
cd ..