template <typename T>
T maximum(T value1, T value2, T value3)
{
    T maxValue = value1;
    if (value2 > maxValue)
        maxValue = value2;
    if (value3 > maxValue)
        maxValue = value3;
    return maxValue;
}