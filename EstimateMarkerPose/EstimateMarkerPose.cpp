#include <opencv2/highgui.hpp>
#include "aruco.h"
using namespace std;

//https://docs.google.com/document/d/1QU9KoBtjSM2kF6ITOjQ76xqL7H0TEtXriJX5kwi9Kgc/edit

//Matrice rotation/translation : https://www.fil.univ-lille1.fr/~aubert/m3ds/m3ds_transformation.pdf


int main(int argc,char **argv)
{
    cv::VideoCapture cap(2);
   cv::Mat im;
   aruco::CameraParameters camera;
   camera.readFromXMLFile(argv[2]);
   aruco::MarkerDetector Detector;
   Detector.setDictionary("ARUCO_MIP_36h12");
   while (true)
   {
       cap.read(im);
        //im=cv::imread(argv[1]);
        auto markers=Detector.detect(im,camera, 0.048);//0.05 is the marker size
        for(auto m:markers){
            aruco::CvDrawingUtils::draw3dAxis(im,m,camera);
            cout<<"rvec = " << m.Rvec<<"   tvec= "<<m.Tvec<<endl;
        }
        cv::imshow("image",im);
        cv::waitKey(1);
       
   }  
   
}
/*int main(int argc,char **argv)
{
   cv::Mat im=cv::imread(argv[1]);
   cout << "ici1" << endl;
   aruco::CameraParameters camera;
   cout << "ici2" << endl;
   camera.readFromXMLFile(argv[2]);
   cout << "ici3" << endl;
   aruco::MarkerDetector Detector;

   Detector.setDictionary("ARUCO_MIP_36h12");
   cout << "ici4" << endl;
   auto markers=Detector.detect(im,camera, 0.039);//0.05 is the marker size
   cout << "ici5" << endl;
   for(auto m:markers){
       aruco::CvDrawingUtils::draw3dAxis(im,m,camera);
       cout<<m.Rvec<<" "<<m.Tvec<<endl;
   }
   cv::imshow("image",im);
   cv::waitKey(0);
}*/

/*int main(int argc,char **argv)
{
    cv::VideoCapture inputVideo;make
    inputVideo.open(2);
    //cv::Ptr<aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(aruco::DICT_6X6_250);
    while (inputVideo.grab()) {
        cv::Mat image, imageCopy;
        inputVideo.retrieve(image);
        image.copyTo(imageCopy);

        std::vector<int> ids;
        std::vector<std::vector<cv::Point2f> > corners;
        aruco::detectMarkers(image, DICT_6X6_250, corners, ids);

        // if at least one marker detected
        if (ids.size() > 0)
            aruco::drawDetectedMarkers(imageCopy, corners, ids);
        
        cv::imshow("out", imageCopy);
        char key = (char) cv::waitKey(waitTime);
        if (key == 27)
            break;
    }
}*/

