#include <vector>
#include <algorithm>

// Bounding box data structure
struct BBox {
    float x1, y1, x2, y2;
    float score;
};

// Compare two bounding boxes by their scores
bool compareBBox(const BBox &a, const BBox &b) {
    return a.score > b.score;
}

std::vector<BBox> nms(std::vector<BBox> &bboxes, float threshold) {
    std::vector<BBox> result;

    // Sort the bounding boxes by their scores
    std::sort(bboxes.begin(), bboxes.end(), compareBBox);

    // Perform non-maximum suppression
    std::vector<int> picked;
    int n = bboxes.size();
    for (int i = 0; i < n; i++) {
        // Stop if there are enough bounding boxes
        if (picked.size() >= n) break;

        // Skip this bounding box if it has been picked
        if (std::find(picked.begin(), picked.end(), i) != picked.end()) continue;

        // Add the current bounding box to the result
        result.push_back(bboxes[i]);

        // Compute the overlap between the current bounding box and the others
        picked.push_back(i);
        for (int j = i + 1; j < n; j++) {
            // Skip this bounding box if it has been picked
            if (std::find(picked.begin(), picked.end(), j) != picked.end()) continue;

            // Compute the overlap between the current bounding box and the other
            float inter_x1 = std::max(bboxes[i].x1, bboxes[j].x1);
            float inter_y1 = std::max(bboxes[i].y1, bboxes[j].y1);
            float inter_x2 = std::min(bboxes[i].x2, bboxes[j].x2);
            float inter_y2 = std::min(bboxes[i].y2, bboxes[j].y2);

            // Compute the intersection area
            float w = std::max(0.0f, inter_x2 - inter_x1 + 1);
            float h = std::max(0.0f, inter_y2 - inter_y1 + 1);
            float inter_area = w * h;

            // Compute the overlap ratio
            float area_i = (bboxes[i].x2 - bboxes[i].x1 + 1) * (bboxes[i].y2 - bboxes[i].y1 + 1);
            float area_j = (bboxes[j].x2 - bboxes[j].x1 + 1) * (bboxes[j].y2 - bboxes[j].y1 + 1);
            float iou = inter_area / (area_i + area_j - inter_area);

            // Skip the other bounding box if the overlap is above the threshold
            if (iou > threshold) {
                picked.push_back(j);
            }
        }
    }

    // Return the result
    return result;
}
