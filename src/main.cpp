#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

bool hit_sphere(const point3 &center, double radius, const ray &r) {
    vec3 oc = r.origin() - center;
    double a = dot(r.direction(), r.direction());
    double b = 2.0 * dot(oc, r.direction());
    double c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    return (discriminant > 0);
}

// conducting a lerp (linear interpolation) between white and blue
color ray_color(const ray& r) {
    if (hit_sphere(point3(0.0,0.0,-1.0), 0.5, r)) {
        return color(1.0, 0.0, 0.0);
    }
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main() {
    // Image
    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    point3 origin = point3(0.0, 0.0, 0.0);
    vec3 horizontal = vec3(viewport_width, 0.0, 0.0);
    vec3 vertical = vec3(0.0, viewport_height, 0.0);
    vec3 lower_left_corner = origin - (horizontal / 2) - (vertical / 2) - vec3(0.0, 0.0, focal_length);

    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int row = image_height-1; row >= 0; --row) {
        std::cerr << "\rScanlines remaining: " << row << ' ' << std::flush;
        for (int column = 0; column < image_width; ++column) {
            double u = double(column) / (image_width-1);
            double v = double(row) / (image_height-1);
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}