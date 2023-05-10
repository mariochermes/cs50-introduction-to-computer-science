import { useState } from 'react';
import { Button, Container, Form, Nav, Navbar, NavDropdown, Offcanvas } from 'react-bootstrap';
import { publicUrl } from '../index';

export default function NavigationBar() {
  const [darkMode, setDarkMode] = useState(true);
  const [isLoggedIn, setIsLoggedIn] = useState(false);

  return (
    <>
      <Navbar bg="light" className="mb-3" expand={false} sticky="top">
        <Navbar.Toggle aria-controls="offcanvasNavbar" className="ms-3"/>
        <Navbar.Offcanvas
          id="offcanvasNavbar"
          aria-labelledby="offcanvasNavbarLabel"
          placement="start"
        >
          <Container fluid className="d-flex flex-column h-100">
            <Offcanvas.Header>
              <Offcanvas.Title id="offcanvasNavbarLabel">
                CyberBrain
              </Offcanvas.Title>
            </Offcanvas.Header>
            <Offcanvas.Body fluid className="d-flex flex-column justify-content-center">
              <Nav>
                <Nav.Link href="#tasks">Tasks</Nav.Link>
                <Nav.Link href="#areas">Areas</Nav.Link>
                <Nav.Link href="#resources">Resources</Nav.Link>
                <Nav.Link href="#archives">Archives</Nav.Link>
              </Nav>
            </Offcanvas.Body>
            <Container className="mt-auto p-3">
              <Nav>
                {isLoggedIn ? (
                  <Nav.Link>
                    Log out
                  </Nav.Link>
                ) : (
                  <>
                    <Nav.Link>
                      Log in
                    </Nav.Link>
                    <Nav.Link>
                      Sign Up
                    </Nav.Link>
                  </>
                )}
              </Nav>
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
