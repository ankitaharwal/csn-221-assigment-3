clear
cd LAC && g++ encoder.cpp -o main && ./main && g++ decoder.cpp -o main && ./main && cd ..
cd IAC && g++ encoder.cpp -o main && ./main && g++ decoder.cpp -o main && ./main && cd ..
cd UAC && g++ encoder.cpp -o main && ./main && g++ decoder.cpp -o main && ./main && cd ..
cd LPC && g++ encoder.cpp -o main && ./main && g++ decoder.cpp -o main && ./main && cd ..
cd IPC && g++ encoder.cpp -o main && ./main && g++ decoder.cpp -o main && ./main && cd ..
cd UPC && g++ encoder.cpp -o main && ./main && g++ decoder.cpp -o main && ./main && cd ..
cd data/comparison/ && python3 comparison.py