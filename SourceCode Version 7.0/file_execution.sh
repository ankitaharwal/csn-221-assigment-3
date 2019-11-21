
echo "LAC:"
echo "running encoder" 
cd LAC 
./main1
echo "running decoder" 
./main && cd ..

echo "IAC:"
echo "running encoder" 
cd IAC 
./main1
echo "running decoder" 
./main && cd ..

echo "UAC:"
echo "running encoder" 
cd UAC 
./main1
echo "running decoder" 
./main && cd ..

echo "LPC:"
echo "running encoder" 
cd LPC 
./main1
echo "running decoder" 
./main && cd ..

echo "IPC:"
echo "running encoder" 
cd IPC 
./main1
echo "running decoder" 
./main && cd ..

echo "UPC:"
echo "running encoder" 
cd UPC 
./main1
echo "running decoder" 
./main && cd ..

