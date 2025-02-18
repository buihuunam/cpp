from collections import deque
#tìm giá trị lớn nhất trong mỗi cửa sổ:
def sliding_window_max(num_list, k):
   
    q = deque()  # Deque lưu các chỉ số
    result = []

    for i, num in enumerate(num_list):
        # Loại bỏ phần tử không còn trong cửa sổ
        if q and q[0] < i - k + 1:
            q.popleft()

        # Loại bỏ tất cả các phần tử trong deque nhỏ hơn num vì chúng sẽ không thể là max
        while q and num_list[q[-1]] <= num:
            q.pop()

        # Thêm chỉ số hiện tại vào deque
        q.append(i)

        # Thêm max vào kết quả khi đã qua đủ k phần tử
        if i >= k - 1:
            result.append(num_list[q[0]])

    return result

# Xử lý chuỗi và đếm từ
def process_string_and_dict(text):
    # Chuyển chuỗi thành chữ thường và tách các từ
    words = text.lower().split()

    # Sử dụng dictionary để đếm số lần xuất hiện của từng từ
    word_count = {}
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    
    return word_count

# Đọc nội dung từ file và xử lý mỗi dòng chuỗi
def read_and_process_file(file_path):
    
    with open(file_path, 'r') as file:
        lines = file.readlines()

    # Xử lý mỗi dòng và lưu kết quả vào list
    processed_lines = []
    for line in lines:
        processed_lines.append(process_string_and_dict(line.strip()))

    return processed_lines

# 1. Tìm giá trị lớn nhất trong mỗi cửa sổ với num_list và k
num_list = [3, 4, 5, 1, -44, 5, 10, 12, 33, 1]
k = 3
print("Max in sliding window:", sliding_window_max(num_list, k))

# 2. Xử lý chuỗi và đếm từ
text = "Hello world hello Python World"
print("Word count:", process_string_and_dict(text))
