import React from 'react';
import { Link } from 'react-router-dom';
import { Button, Container, Image } from 'react-bootstrap';
import { publicUrl } from '../index';

const HomePage = () => {
  return (
    <Container className="d-flex flex-column align-items-center justify-content-center h-100" style={{ height: '100vh' }}>
      <Image src={`${publicUrl}/sunIconDark.png`} className="align-self-end" width={25} height={25} />
      <Image src={`${publicUrl}/cyberbrainLogo.png`} width={300} height={300}/>
      <h1 className="text-center mb-5">Cyberbrain</h1>
      <Image src={`${publicUrl}/cyberElement.png`} className="mb-5" />
      <div className="d-flex justify-content-center w-100">
        <Button variant="primary" className="m-2">
          <Link to="/tasks" className="text-white text-decoration-none">
            <i className="bi bi-card-checklist"></i>
            <span className="ms-2">Tasks</span>
          </Link>
        </Button>
        <Button variant="primary" className="m-2">
          <Link to="/areas" className="text-white text-decoration-none">
            <i className="bi bi-columns"></i>
            <span className="ms-2">Areas</span>
          </Link>
        </Button>
        <Button variant="primary" className="m-2">
          <Link to="/resources" className="text-white text-decoration-none">
            <i className="bi bi-folder2-open"></i>
            <span className="ms-2">Resources</span>
          </Link>
        </Button>
        <Button variant="primary" className="m-2">
          <Link to="/archives" className="text-white text-decoration-none">
            <i className="bi bi-archive"></i>
            <span className="ms-2">Archives</span>
          </Link>
        </Button>
      </div>
    </Container>
  );
};

export default HomePage;
