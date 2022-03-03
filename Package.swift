// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "Diffusion",
    products: [
        .library(
            name: "Diffusion",
            targets: ["Diffusion"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(name: "Diffusion", path: "./Sources/Diffusion.xcframework")
    ]
)
