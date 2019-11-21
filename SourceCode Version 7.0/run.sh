clear
./file_compiling.sh
./file_preprocess.sh
./file_execution.sh
cd data/comparison
python3 comparison.py
cd ..
cd ..
./file_preprocess_2.sh
./file_execution.sh
cd data/comparison
python3 comparison.py 2
cd ..
cd ..
./file_preprocess_3.sh
./file_execution.sh
cd data/comparison
python3 comparison.py 3
cd ..
cd ..