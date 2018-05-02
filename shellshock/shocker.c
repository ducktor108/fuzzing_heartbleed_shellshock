char val[1024 * 16];

main() {
    read(0, val, sizeof(val) - 1);
    setenv("TEST_VARIABLE", val, 1);
    execl("./bash", "bash", "-c", ":", 0);
}
