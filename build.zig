const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const flags = [_][]const u8{
        "-Wall",
        "-Wextra",
        "-Werror=return-type",
        "-g",
        "-pedantic",
        "-std=c++17",
    };

    const exe = b.addExecutable("tic-tac-toe", null);
    exe.addCSourceFile("main.cpp", &flags);
    exe.linkLibCpp();
    exe.install();
}
