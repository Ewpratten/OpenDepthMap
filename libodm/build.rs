fn main() {
    // Compile the LeapMotion wrapper (and Leap itself)
    cc::Build::new()
        .file("cpp/wrapper.cc")

        // Handle LeapMotion errors
        .flag("-Wno-deprecated")
        .flag("-Wno-deprecated-copy")

        // Tell the compiler where leap is
        .flag("-L dist")
        .flag("-lLeap")

        // Link with stdc++
        .flag("-lstdc++")

        // Compile into a proper library
        .compile("leapwrapper");

    // Set up the linker to include Leap
    println!("cargo:rustc-link-search=native=libodm/dist");
    println!("cargo:rustc-link-lib=Leap");

    // Set up the linker to include stdc++
    println!("cargo:rustc-link-lib=static-nobundle=stdc++");

    // Make cargo auto-rebuild these files
    println!("cargo:rerun-if-changed=libodm/build.rs");
    println!("cargo:rerun-if-changed=libodm/cpp/wrapper.cc");
}
