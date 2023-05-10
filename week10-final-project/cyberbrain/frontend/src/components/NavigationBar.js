import { useState } from 'react';
import { Button, Container, Form, Nav, Navbar, NavDropdown, Offcanvas } from 'react-bootstrap';
import { publicUrl } from '../index';

export default function NavigationBar() {
  const [darkMode, setDarkMode] = useState(true);

  return (
    <>
      <Navbar bg="light" expand={false} className="mb-3">
        <Navbar.Toggle aria-controls="offcanvasNavbar" />
        <Navbar.Offcanvas
          id="offcanvasNavbar"
          aria-labelledby="offcanvasNavbarLabel"
          placement="start"
        >
          <Container fluid className="d-flex flex-column justify-content-between h-100">
            <Container className="p-0">
              <Offcanvas.Header>
                <Offcanvas.Title id="offcanvasNavbarLabel">
                  CyberBrain
                </Offcanvas.Title>
              </Offcanvas.Header>
            </Container>
            <Container className="p-0">
              <Offcanvas.Body>
                <Nav className="justify-content-end flex-grow-1 pe-3">
                  <Nav.Link href="#tasks">Tasks</Nav.Link>
                  <Nav.Link href="#areas">Areas</Nav.Link>
                  <Nav.Link href="#resources">Resources</Nav.Link>
                  <Nav.Link href="#archives">Archives</Nav.Link>
                </Nav>
              </Offcanvas.Body>
            </Container>
          </Container>
        </Navbar.Offcanvas>
        <Button
          className="toggle-mode-button"
          onClick={() => setDarkMode(!darkMode)}
          variant="outline-transparent"
        >
          <img src={`${publicUrl}/sun-icon-dark.png`} alt="sun icon" className="align-self-end" width={28} height={28} />
        </Button>
      </Navbar>
    </>
  );
}
