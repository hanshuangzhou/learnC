int main() {
    int girls = 3, boys = 4;
    auto totalChild = [=]() -> int { return girls + boys; };
    
    return totalChild();
}