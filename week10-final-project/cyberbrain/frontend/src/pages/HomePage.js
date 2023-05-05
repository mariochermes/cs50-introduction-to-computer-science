import React from 'react';
import { Button, Col, Container, Image, Row } from 'react-bootstrap';
import { publicUrl } from '../index';
import { SteppedLineTo } from 'react-lineto';

const HomePage = () => {
  return (
    <Container className="align-items-center d-flex flex-column justify-content-between h-100 min-vh-100 py-5" maxWidth={1200}>
      <Row className="justify-content-end w-100">
        <Col xs="auto">
          <Image src={`${publicUrl}/sun-icon-dark.png`} className="align-self-end" width={30} height={30} />
        </Col>
      </Row>
      <Row className="align-items-center justify-content-center text-center w-100">
        <Col xs={12} sm={6} lg={4}>
          <Image fluid src={`${publicUrl}/cyberbrain-logo-512.png`} className="mb-3" maxWidth={350} maxHeight={350} />
          <h1 className="my-3">CyberBrain</h1>
        </Col>
        <SteppedLineTo from="A" to="B" orientation="v" />
      </Row>
      <Row className="pb-5 w-100 h-100">
        <Col className="text-center w-100" xs={12} sm={8} lg={6}>
          <Row className="justify-content-evenly">
            <Col xs={6} md={2} className="text-center mb-3">
              <button className="rounded-2 w-100 h-100">
                <img src={`${publicUrl}/tasks-icon.png`} alt="Tasks Icon" className="mb-2" width={64} height={64} />
                <h5>Tasks</h5>
              </button>
            </Col>
            <Col xs={6} md={2} className="text-center mb-3">
              <button className="rounded-2 w-100 h-100">
                <img src={`${publicUrl}/areas-icon.png`} alt="Areas Icon" className="mb-2" width={64} height={64} />
                <h5>Areas</h5>
              </button>
            </Col>
            <Col xs={6} md={2} className="text-center mb-3">
              <button className="rounded-2 w-100 h-100">
                <img src={`${publicUrl}/resources-icon.png`} alt="Resources Icon" className="mb-2" width={64} height={64} />
                <h5>Resources</h5>
              </button>
            </Col>
            <Col xs={6} md={2} className="text-center mb-3">
              <button className="rounded-2 w-100 h-100">
                <img src={`${publicUrl}/archives-icon.png`} alt="Archives Icon" width={64} height={64} />
                <h5>Archives</h5>
              </button>
            </Col>
          </Row>
        </Col>
      </Row>
    </Container>
  );
};

export default HomePage;
