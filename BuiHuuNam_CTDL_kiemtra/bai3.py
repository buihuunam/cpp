import re

# Hàm để đọc nội dung file và trả về một list các từ
def read_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            content = file.readlines()
        return content
    except FileNotFoundError:
        print("File không tồn tại.")
        return []

# Hàm để tách các từ từ mỗi dòng và chuyển thành chữ thường
def extract_words(lines):
    words = []
    for line in lines:
        # Dùng regex để tách từ, chỉ lấy chữ cái
        words += re.findall(r'\b[a-zA-Z]+\b', line.lower())
    return words

# Hàm để đếm số lần xuất hiện của các từ trong danh sách
def count_word_occurrences(words):
    word_count = {}
    for word in words:
        if word in word_count:
            word_count[word] += 1
        else:
            word_count[word] = 1
    return word_count

# Hàm chính để xử lý toàn bộ quá trình
def count_words_in_file(file_path):
    lines = read_file(file_path)  # Đọc nội dung file
    if not lines:  # Nếu file không tồn tại hoặc không có nội dung
        return {}
    
    words = extract_words(lines)  # Tách từ
    word_count = count_word_occurrences(words)  # Đếm từ
    return word_count

# Ví dụ sử dụng:
file_path = 'D:/bai_tap_ctdl_gt/cpp/thi/P1_data.txt'  # Thay đổi với đường dẫn thực tế đến file .txt
result = count_words_in_file(file_path)
print(result)
