
#include <osgViewer/viewer>
#include <osgDB/ReadFile>
#include <osgEarth/MapNode>
#include <osgEarthUtil/EarthManipulator>

int main()
{
	osg::ref_ptr<osg::Group> root = new osg::Group;
	//osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("cow.osg");
	osg::ref_ptr<osg::Node> node = osgDB::readNodeFile("D:\\runtime\\osgEarth2.8\\tests\\feature_geom.earth");
	root->addChild(node);
	osg::ref_ptr<osgViewer::Viewer> viewer = new osgViewer::Viewer;
	viewer->setSceneData(root);

	osg::ref_ptr<osgEarth::MapNode> mapNode = dynamic_cast<osgEarth::MapNode*> ( node.get());
	osg::ref_ptr<osgEarth::Util::EarthManipulator> em = new osgEarth::Util::EarthManipulator;
	em->setNode(mapNode);
	viewer->setCameraManipulator(em);
	viewer->run();

}

