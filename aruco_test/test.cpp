#include <opencv2/aruco.hpp>

cv::Mat markerImage;
cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
cv::aruco::drawMarker(dictionary, 23, 200, markerImage, 1);
cv::imwrite("marker23.png", markerImage);