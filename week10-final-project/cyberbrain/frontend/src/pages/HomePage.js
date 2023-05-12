import React from 'react';
import { Button, Col, Container, Image, Row } from 'react-bootstrap';
import { publicUrl } from '../index';
import NavigationBar from '../components/NavigationBar';
import PageButton from '../components/PageButton';
import { SteppedLineTo } from 'react-lineto';

export default function HomePage() {
  return (
    <Container className="align-items-center d-flex flex-column flex-grow-1 justify-content-between h-100 py-5">
      <Row className="justify-content-end w-100">
      </Row>
      <Row className="align-items-center justify-content-center text-center w-100">
        <Col xs="auto">
          <Image alt="CyberBrain logo" src={`${publicUrl}/cyberbrain-logo-512.png`} width={350}/>
          <h1 className="page-title">CyberBrain<span class="blink">.</span></h1>
        </Col>
      </Row>
      {/* <SteppedLineTo borderColor="#B7B7B7" from="page-title" to="tasks-page-button" orientation="v" fromAnchor="bottom" toAnchor="top" /> */}
      <Row className="w-100 h-100">
        <Col className="text-center w-100" xs={12} lg={4}>
          <Row className="justify-content-evenly">
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <PageButton pageName="tasks">

              </PageButton>
            </Col>
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <PageButton pageName="areas">

              </PageButton>
            </Col>
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <PageButton pageName="resources">

              </PageButton>
            </Col>
            <Col xs={6} md={3} lg={2} className="text-center mb-3">
              <PageButton pageName="archives">

              </PageButton>
            </Col>
          </Row>
        </Col>
      </Row>
    </Container>
  );
};
