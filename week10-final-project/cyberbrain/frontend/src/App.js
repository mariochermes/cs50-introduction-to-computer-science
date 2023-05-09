import { BrowserRouter , Routes, Route } from 'react-router-dom';
import HomePage from './pages/HomePage';
import OffCanvasDrawer from './components/OffCanvasDrawer'
import './App.css';

export default function App() {
  return (
    <>
      <BrowserRouter>
        <Routes>
          <Route path="/" element={<OffCanvasDrawer />} />
        </Routes>
      </BrowserRouter>
    </>
  );
}
