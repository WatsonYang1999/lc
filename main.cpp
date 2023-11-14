#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// 判断两个字符串是否是旋转字符串
bool areRotations(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::string str1str1 = str1 + str1;
    return str1str1.find(str2) != std::string::npos;
}

int main() {
    int n;
    std::cout << "输入字符串数量 n: ";
    std::cin >> n;

    std::vector<std::string> strings(n);
    std::unordered_map<std::string, bool> rotationMap;

    for (int i = 0; i < n; ++i) {
        std::cout << "输入第 " << i + 1 << " 个字符串: ";
        std::cin >> strings[i];

        // 将字符串的所有旋转版本添加到哈希表中
        std::string original = strings[i];
        for (int j = 0; j < original.length(); ++j) {
            std::rotate(original.begin(), original.begin() + 1, original.end());
            rotationMap[original] = true;
        }
    }

    // 检查是否存在两个字符串是旋转字符串
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (rotationMap.count(strings[i]) > 1) {
            found = true;
            break;
        }
    }

    if (found) {
        std::cout << "存在两个字符串是旋转字符串。" << std::endl;
    } else {
        std::cout << "不存在两个字符串是旋转字符串。" << std::endl;
    }

    return 0;
}
