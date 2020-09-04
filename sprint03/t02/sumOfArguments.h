template <class T>
T sumOfArguments(T t) {
    return t;
}

template <class T, class ...Ts>
T sumOfArguments(T t, Ts... args) {
    return t += sumOfArguments(args...);
}
